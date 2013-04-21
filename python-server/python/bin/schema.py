#! /usr/bin/env python2.7

import sqlite3 as db
import os.path

def create_db(name, path):
    '''Creates a SQLite3 database at the specified location(path) with the
    specified name
    '''

    c = db.connect(os.path.join(path, name))

    c.execute('''CREATE TABLE user(
                id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
                nick TEXT UNIQUE,
                email TEXT UNIQUE,
                password TEXT,
                image_reference TEXT
            )''')

    c.execute('''CREATE TABLE upload(
                id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
                user_id INTEGER NOT NULL,
                filename TEXT,
                timestamp INTEGER,
                FOREIGN KEY(user_id) REFERENCES user(id)
            )''')

    c.execute('''CREATE TABLE processed(
                id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
                user_id INTEGER NOT NULL,
                upload_id INTEGER NOT NULL,
                filename TEXT,
                timestamp INTEGER,
                FOREIGN KEY(user_id) REFERENCES user(id),
                FOREIGN KEY(upload_id) REFERENCES upload(id)
            )''')

    #TODO:create the session table

    c.close()

if __name__ == "__main__":
    create_db('upload.db', os.path.abspath('..'))

