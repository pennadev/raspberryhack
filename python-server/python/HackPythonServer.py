from bottle import Bottle, post, get, route, run, template
import cgi
import cgitb; cgitb.enable()
import os, sys
try: # Windows needs stdio set for binary mode.
    import msvcrt
    msvcrt.setmode (0, os.O_BINARY) # stdin  = 0
    msvcrt.setmode (1, os.O_BINARY) # stdout = 1
except ImportError:
    pass

app = Bottle()

def list_filter(config):
    ''' Matches a comma separated list of numbers. '''
    delimiter = config or ','
    regexp = r'\d+(%s\d)*' % re.escape(delimiter)

    def to_python(match):
        return map(int, match.split(delimiter))

    def to_url(numbers):
        return delimiter.join(map(str, numbers))

    return regexp, to_python, to_url

app.router.add_filter('list', list_filter)

UPLOAD_DIR = "/tmp"

@route('/:name')
def index(name='upload'):
    return template('<b>Hello {{name}}</b>', name=name)

FILE_NAME = 'file'
@app.get('/:name')
def indexPage(name='upload'):
	return template('UploadFiles', file = FILE_NAME)

@app.post('/:name')
def index(name='upload'):
	save_uploaded_file (FILE_NAME, UPLOAD_DIR)

def save_uploaded_file (form_field, upload_dir):
    """This saves a file uploaded by an HTML form.
       The form_field is the name of the file input field from the form.
       For example, the following form_field would be "file_1":
           <input name="file_1" type="file">
       The upload_dir is the directory where the file will be written.
       If no file was uploaded or if the field does not exist then
       this does nothing.
    """
    form = cgi.FieldStorage()
    if not form.has_key(form_field): return
    fileitem = form[form_field]
    if not fileitem.file: return
    fout = file (os.path.join(UPLOAD_DIR, fileitem.filename), 'wb')
    while 1:
        chunk = fileitem.file.read(100000) 
        if not chunk: break
        fout.write (chunk)
    fout.close()

@app.run(host='10.10.0.25', port=8080)
