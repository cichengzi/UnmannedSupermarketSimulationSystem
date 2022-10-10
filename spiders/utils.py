import requests
import json
import random
import datetime


def download_image(image_url, image_path):
    image_request = requests.get(image_url)
    with open(image_path, 'wb+') as f:
        f.write(image_request.content)


def extract_commodities():
    commodity_info_list = json.load(open('cache/goods.txt'))['result']
    start = 1
    commodities_str = ''
    for i, commodity_info in enumerate(commodity_info_list):
        if start > 100:
            break
        pic_path = f'/Users/cichengzi/Desktop/code/UnmannedSupermarketSimulationSystem/resources/{start}.jpg'
        download_image(commodity_info['thumb_url'], pic_path)
        start += 1
        name = commodity_info['short_name']
        price = commodity_info['normal_price'] / 100
        number = random.randint(100, 1000)
        idx = int(datetime.datetime.now().timestamp() * 1000000)
        description = commodity_info['goods_name']
        commodity = [pic_path, name, price, number, idx, description]
        commodities_str += ','.join(list(map(str, commodity))) + '\n'
    with open('../data/commodities.txt', 'w') as f:
        f.write(commodities_str)


'''
url = 'https://img.pddpic.com/gaudit-image/2022-03-02/0ca49f34d9f188d9da231d48c60bafe9.jpeg'
path = ''
download_image(url, path)
'''

extract_commodities()