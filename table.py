import sqlite3

conn = sqlite3.connect("userdb.db")
c = conn.cursor()

# SQL_STATEMENT = """
# CREATE TABLE IF NOT EXISTS Forum (
#     id INTEGER PRIMARY KEY AUTOINCREMENT,
#     caption VARCHAR(30)
# )
# """

SQL_STATEMENT = """
CREATE TABLE IF NOT EXISTS Register (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username VARCHAR(30),
    password VARCHAR(30),
    email VARCHAR(30),
    phone VARCHAR(15)
)
"""

c.execute(SQL_STATEMENT)

conn.commit()
conn.close()
