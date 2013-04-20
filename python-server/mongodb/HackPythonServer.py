from bottle import route, run, template

@route('/:name')
def index(name='upload'):
    return template('<b>Hello {{name}}</b>!', name=name)

run(host='10.10.0.25', port=8080)