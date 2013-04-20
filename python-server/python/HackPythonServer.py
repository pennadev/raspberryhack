from bottle import Bottle
from bottle import post, get, route, run, template, request
import cgi
import cgitb; cgitb.enable()
import os, sys
from os import path

try: # Windows needs stdio set for binary mode.
    import msvcrt
    msvcrt.setmode (0, os.O_BINARY) # stdin  = 0
    msvcrt.setmode (1, os.O_BINARY) # stdout = 1
except ImportError:
    pass

HOST = '10.10.0.25'
#HOST = 'localhost' #windows dev machine
UPLOAD_DIR = "./tmp"
FILE_NAME = 'file'

@route('/:name', method='POST')
def do_upload(name = 'upload'):
    form_name = request.forms.name
    data = request.files.data
    raw = data.file.read() # This is dangerous for big files
    filename = data.filename
    return "Hello %s! You uploaded %s (%d bytes)." % (name, filename, len(raw))
    
@route('/', method = 'get')
def index():
    return '<b>Hello</b>'

@route('/:name', method = 'GET')
def indexPage(name='upload'):
	return template('UploadFiles', file = FILE_NAME)

def save_uploaded_file (form_field, upload_dir):
    print ("""This saves a file uploaded by an HTML form.
       The form_field is the name of the file input field from the form.
       For example, the following form_field would be "file_1":
           <input name="file_1" type="file">
       The upload_dir is the directory where the file will be written.
       If no file was uploaded or if the field does not exist then
       this does nothing.
    """ + upload_dir)
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


def webServer():
  run(host=HOST, port=8080)

if __name__ == "__main__":
  print 'Listening on 8080...'
  webServer()