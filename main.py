from flask import Flask, request, jsonify
import sqlite3
import hashlib
import json
# from encryption import decrypt_message, fetchPubKey
from flask_cors import CORS

app = Flask(__name__)
CORS(app)


#------------------END TESTINGA REA
# Database
# @app.route('/generate_token', methods=['GET'])
def generate_token(device_id, username):
  data = request.get_json()
  device_id = data.get('device_id')
  username = data.get('username')

  combined_str = f"{device_id}-{username}"
  hashed_token = hashlib.sha256(combined_str.encode()).hexdigest()
  return jsonify({'token': hashed_token})


@app.route('/generate_token', methods=['POST'])
def generate_post_token():
  data = request.get_json()
  device_id = data.get('udid')

  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute("SELECT username FROM Register WHERE udid=?", (device_id))

  result = cursor.fetchone()
  conn.close()

  username = result[0]

  token = generate_token(device_id, username)

  return jsonify({'token': token})


@app.route('/', methods=['GET'])
def my_route():
  #GET{print('hi')
  return 'HunianKu'

@app.route('/tables', methods=['GET'])
def my_tables():
  #GET{print('hi')
  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute(
      "SELECT name FROM sqlite_master WHERE type ='table' AND name NOT LIKE 'sqlite_%'")

  tables = cursor.fetchall()
  conn.commit()
  conn.close()
  return jsonify({'tables': tables})

# Register a user
@app.route('/users', methods=['POST'])
def register_user():
  # request = [udid, username, password]
  data = request.get_json()

  # token = data.get('token')
  username = data.get('username')
  password = data.get('password')
  phone = data.get('phone')
  email = data.get('email')

  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute(
      "INSERT INTO Register (username, password, phone, email) VALUES (?, ?, ?, ?)",
      (username, password, phone, email))

  conn.commit()
  conn.close()

  return jsonify({'status': 'success'})


@app.route('/users', methods=['GET'])
def get_all_users():
  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute("SELECT * FROM Register")
  users_data = cursor.fetchall()

  conn.close()

  users_list = []
  for user_data in users_data:
    user_dict = {
        # 'udid': user_data[0],
        'username': user_data[1],
        'password': user_data[2],
        'phone': user_data[3],
        'email': user_data[4]
    }
    users_list.append(user_dict)

  return jsonify({'users': users_list})


# @app.errorhandler(Exception)
# def handle_error(e):
#     print(str(e))
#     return jsonify(error=str(e)), 500


@app.route('/verify', methods=['POST'])
def verifyUser():
  data = request.get_json()
  username = data.get('username')
  password = data.get('password')

  if not username or not password:
    return jsonify({
        'status': 'failed',
        'message': 'Username and password are required'
    }), 400

  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute("SELECT * FROM Register WHERE username=? AND password=?",
                 (username, password))
  result = cursor.fetchone()

  conn.close()

  if result:
    print("Correct password for the given username.")
    return jsonify({'status': 'success'})
  else:
    print("Incorrect password or username not found.")
    return jsonify({
        'status': 'failed',
        'message': 'Incorrect password or username not found'
    }), 401


# @app.route('/pubkey', methods=['GET'])
# def pubKey():
#   key = fetchPubKey()
#   return jsonify({'publicKey': key})


@app.route('/property', methods=['POST'])
def add_property():
  # request = [udid, username, password]
  data = request.get_json()

  # token = data.get('token')
  udid = data.get('udid')
  action = data.get('action')
  type = data.get('type')
  lokasi = data.get('lokasi')
  harga = data.get('harga')
  area = data.get('area')
  kTidur = data.get('kTidur')
  kMandi = data.get('kMandi')
  kMandiKos = data.get('kMandiKos')
  tipeKost = data.get('tipeKost')
  ketinggian = data.get('ketinggian')
  sewa = data.get('sewa')
  image = data.get('image')
  date = data.get('date')
  status = data.get('status')
  desc = data.get('deskripsi')

  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute(
      "INSERT INTO properties (udid, action, status, type, lokasi, harga, area, kTidur, kMandi,kMandiKos, tipeKost, ketinggian, sewa, image, date, status, desc) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,?,?)",
      (udid, action, status, type, lokasi, harga, area, kTidur, kMandi,
       kMandiKos, tipeKost, ketinggian, sewa, image, date, status, desc))

  conn.commit()

  conn.close()

  return jsonify({'message': 'Post created successfully'})


@app.route('/properties', methods=['GET'])
def get_all_beli_rumah():
  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute("SELECT * FROM properties")
  datas = cursor.fetchall()

  conn.close()

  data_list = []
  for data in datas:
    data_dict = {
        'id': data[0],
        'udid': data[1],
        'action': data[2],
        'type': data[3],
        'lokasi': data[4],
        'harga': data[5],
        'area': data[6],
        'kTidur': data[7],
        'kMandi': data[8],
        'kMandiKos': data[9],
        'tipeKost': data[10],
        'ketinggian': data[11],
        'sewa': data[12],
        #'image': data[13],
        'date': data[14],
        'status': data[15],
        'desc': data[16]
    }
    data_list.append(data_dict)

  return jsonify({'property': data_list})


# Filter


@app.route('/filter', methods=['POST'])
def filter_property():
  # request = [udid, username, password]
  data = request.get_json()
  print(data)

  ### Get all data
  udid = data.get('udid')
  action = data.get('action')
  type = data.get('type')
  lokasi = data.get('lokasi')
  harga1 = data.get('harga1')
  area1 = data.get('area1')
  harga2 = data.get('harga2')
  area2 = data.get('area2')
  kTidur = data.get('kTidur')
  kMandi = data.get('kMandi')
  kMandiKos = data.get('kMandiKos')
  tipeKost = data.get('tipeKost')
  ketinggian1 = data.get('ketinggian1')
  ketinggian2 = data.get('ketinggian2')
  sewa = data.get('sewa')
  image = data.get('image')
  date = data.get('date')
  status = data.get('status')

  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  ##Beli Komersial
  if action == 'Beli' and type == 'Komersial':
    #print('masuk paeko')
    cursor.execute(
        "SELECT * FROM properties WHERE status='Ready' AND action ='Jual' AND type='Komersial' AND lokasi=? AND harga >= ? AND harga <= ? AND area >= ? AND area <=? AND kTidur=? AND kMandi=? ",
        (lokasi, harga1, harga2, area1, area2, kTidur, kMandi))

  ##Beli Rumah
  elif action == 'Beli' and type == 'Rumah':
    #print("tes")
    cursor.execute(
        "SELECT * FROM properties WHERE status='Ready' AND action ='Jual' AND type='Rumah' AND lokasi=? AND harga >= ? AND harga <= ? AND area >= ? AND area <=? AND kTidur=? AND kMandi=? ",
        (lokasi, harga1, harga2, area1, area2, kTidur, kMandi))

  ##Beli Apartement
  elif action == 'Beli' and type == 'Apartement':
    cursor.execute(
        "SELECT * FROM properties WHERE status='Ready' AND action ='Jual' AND type='Apartement' AND lokasi=? AND harga >= ? AND harga <= ? AND area >= ? AND area <=? AND kTidur=? AND kMandi=? ",
        (lokasi, harga1, harga2, area1, area2, kTidur, kMandi))

  ##Beli Tanah
  elif action == 'Beli' and type == 'Tanah':
    cursor.execute(
        "SELECT * FROM properties WHERE status='Ready' AND action ='Jual' AND type='Tanah' AND lokasi=? AND harga >= ? AND harga <= ? AND area >= ? AND area <=? AND ketinggian>=? AND ketinggian <=? ",
        (
            lokasi,
            harga1,
            harga2,
            area1,
            area2,
            ketinggian1,
            ketinggian2,
        ))

  ##Beli Kost
  elif action == 'Beli' and type == 'Kost':
    cursor.execute(
        "SELECT * FROM properties WHERE status='Ready' AND action ='Jual' AND type='Kost' AND lokasi=? AND harga >= ? AND harga <= ? AND area >= ? AND area <=? AND kMandiKos=? AND tipeKost=? AND kTidur=? AND kMandi=? ",
        (lokasi, harga1, harga2, area1, area2, kMandiKos, tipeKost, kTidur,
         kMandi))

  ##Sewa Komersial
  elif action == 'Sewa' and type == 'Komersial':
    #print('masuk paeko')
    cursor.execute(
        "SELECT * FROM properties WHERE status='Ready' AND action ='Sewa' AND type='Komersial' AND lokasi=? AND harga >= ? AND harga <= ? AND area >= ? AND area <=? AND kTidur=? AND kMandi=? AND sewa=?",
        (lokasi, harga1, harga2, area1, area2, kTidur, kMandi, sewa))

  ##Sewa Rumah
  elif action == 'Sewa' and type == 'Rumah':
    #print("tes")
    cursor.execute(
        "SELECT * FROM properties WHERE status='Ready' AND action ='Sewa' AND type='Rumah' AND lokasi=? AND harga >= ? AND harga <= ? AND area >= ? AND area <=? AND kTidur=? AND kMandi=? AND sewa=?",
        (lokasi, harga1, harga2, area1, area2, kTidur, kMandi, sewa))

  ##Sewa Apartement
  elif action == 'Sewa' and type == 'Apartement':
    cursor.execute(
        "SELECT * FROM properties WHERE status='Ready' AND action ='Sewa' AND type='Apartement' AND lokasi=? AND harga >= ? AND harga <= ? AND area >= ? AND area <=? AND kTidur=? AND kMandi=? AND sewa=?",
        (lokasi, harga1, harga2, area1, area2, kTidur, kMandi, sewa))

  ##Sewa Tanah
  elif action == 'Sewa' and type == 'Tanah':
    cursor.execute(
        "SELECT * FROM properties WHERE status='Ready' AND action ='Sewa' AND type='Tanah' AND lokasi=? AND harga >= ? AND harga <= ? AND area >= ? AND area <=? AND ketinggian>=? AND ketinggian <=? AND sewa=?",
        (
            lokasi,
            harga1,
            harga2,
            area1,
            area2,
            ketinggian1,
            ketinggian2,
            sewa,
        ))

  ##Sewa Kost
  elif action == 'Sewa' and type == 'Kost':
    #print("im here")
    cursor.execute(
        "SELECT * FROM properties WHERE status='Ready' AND action='Sewa' AND type='Kost' AND lokasi=? AND harga >= ? AND harga <= ? AND area >= ? AND area <= ? AND kMandiKos=? AND tipeKost=? AND kTidur=? AND kMandi=? AND sewa=?",
        (
            lokasi,
            harga1,
            harga2,
            area1,
            area2,
            kMandiKos,
            tipeKost,
            kTidur,
            kMandi,
            sewa,
        ))
    # cursor.execute("SELECT id FROM properties WHERE status='Ready' AND type == 'Kost' AND action='Sewa' AND lokasi=? AND harga >= ? AND harga <= ? AND area >= ? AND area <= ? AND kMandiKos=?", (lokasi, harga1, harga2, area1, area2, kMandiKos,))

  #Assign the data
  filteredData = cursor.fetchall()
  # print('filteredData:')
  # print(filteredData)

  conn.commit()

  conn.close()
  return jsonify(filteredData), 200


@app.route('/myListing', methods=['POST'])
def myListing():
  data = request.get_json()

  udid = data.get('udid')

  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute("SELECT * FROM properties WHERE udid=?", (udid, ))

  myListingData = cursor.fetchall()

  conn.commit()

  conn.close()
  return jsonify(myListingData), 200


@app.route('/detailProperty', methods=['POST'])
def send_detail_property():
  data = request.get_json()
  id = data.get('id')

  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute("SELECT * FROM properties WHERE id=?", (id, ))

  detailProperty = cursor.fetchone()
  #print(detailProperty)

  cursor.execute("SELECT udid FROM properties WHERE id=?", (id, ))

  udid = cursor.fetchone()[0]
  #print(udid)

  conn.commit()

  cursor.execute("SELECT phone,username,image FROM Register WHERE udid=?",
                 (udid, ))

  sellerData = cursor.fetchone()
  #print(phone)

  detailPropertyData = list(detailProperty) + list(sellerData)
  #print(detailPropertyData)
  conn.close()
  print('data fetched successfully')

  return jsonify(detailPropertyData), 200
  #else:
  # return jsonify({'error': 'Data not found'}), 404


@app.route('/favoritesData', methods=['POST'])
def favorites_data():
  # request = [udid, username, password]
  data = request.get_json()
  print(data)

  favorites = data.get('favorites')
  print(favorites)

  favoritesData = []

  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  for favorite in favorites:
    cursor.execute("SELECT * FROM Properties WHERE id = ?", (favorite, ))
    data = cursor.fetchone()
    favoritesData.append(data)

  conn.commit()
  conn.close()
  print('data fetched successfully')

  return jsonify(favoritesData), 200


@app.route('/postForum', methods=['POST'])
def add_post_forum():
  data = request.get_json()
  caption = data.get('caption')

  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute("INSERT INTO Forum (caption) VALUES (?)", (caption, ))

  conn.commit()
  conn.close()

  return jsonify({'message': 'Post created successfully'})


@app.route('/postForum', methods=['GET'])
def get_all_post_forum():
  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute("SELECT * FROM Forum")
  datas = cursor.fetchall()

  conn.close()

  data_list = []
  for data in datas:
    data_dict = {
        'id': data[0],
        # 'udid': data[1],
        # 'username': data[2],
        'caption': data[1],
        # 'komen': data[4],
        # 'date': data[5],
        # 'image': data[6]
    }
    data_list.insert(0, data_dict)

  return jsonify({'Forum': data_list})


@app.route('/postKomen', methods=['POST'])
def get_post_komen():
  data = request.get_json()
  udid = data.get('udid')
  komen = data.get('komen')
  id = data.get('id')

  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute("SELECT username FROM Register WHERE udid = ?", (udid, ))
  result = cursor.fetchone()

  if result:
    username = result[0]

    cursor.execute(
        "INSERT INTO komen(id, udid, username, komen) VALUES (?, ?, ?, ?)",
        (id, udid, username, komen))

    conn.commit()
    cursor.execute("SELECT * FROM komen WHERE id = ?", (id, ))
    comments = cursor.fetchall()
    conn.close()
    return jsonify({'comments': comments})
  else:
    conn.close()
    return jsonify({'error':
                    'User not found for the provided udid and id'}), 404


# if __name__ == '__main__':
#   app.run(host="0.0.0.0", port=9000)

# Profile Picture


@app.route('/profilePicture', methods=['POST'])
def update_profile_picture():
  data = request.get_json()
  udid = data.get('udid')
  image = data.get('image')
  #print(image)

  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute("INSERT INTO Register (udid, image) VALUES (?, ?)",
                 (udid, image))

  conn.commit()
  conn.close()
  return jsonify({'message': 'Profile picture updated successfully'})


@app.route('/profilePictureData', methods=['GET'])
def get_all_profile_picture_data():
  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute("SELECT * FROM Register")
  pictures = cursor.fetchall()

  conn.close()

  picture_list = []
  for picture in pictures:
    picture_dict = {'id': picture[0], 'udid': picture[1], 'image': picture[2]}
    picture_list.append(picture_dict)

  return jsonify({'Profile Picture': picture_list})


@app.route('/postKomen', methods=['GET'])
def get_komen():
  conn = sqlite3.connect('userdb.db')
  cursor = conn.cursor()

  cursor.execute("SELECT * FROM Komen")
  result = cursor.fetchall()

  conn.commit()
  conn.close()

  return jsonify(result), 200


if __name__ == '__main__':
  app.run(host="0.0.0.0", port=9000)
