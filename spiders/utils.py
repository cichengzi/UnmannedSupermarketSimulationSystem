import requests
import json
import random
import datetime
import time
from CommoditySpider import download_info


def download_image(image_url, image_path):
    headers = {
        'User-Agent': 'Mozilla/5.0'
    }
    try:
        image_request = requests.get(image_url, headers=headers, timeout=5)
        status_code = requests.codes['\o/']
        with open(image_path, 'wb+') as f:
            f.write(image_request.content)
    except:
        status_code = 333
        content = open('/Users/cichengzi/Desktop/code/UnmannedSupermarketSimulationSystem/resources/1.jpg', 'rb+').read()
        with open(image_path, 'wb+') as f:
            f.write(content)

    return status_code


def extract_commodities(commodity_info_list, start):
    print(f'num of commodities: {len(commodity_info_list)}')
    commodities_str = open('../data/commodities.txt', 'r').read()
    for i, commodity_info in enumerate(commodity_info_list):
        time.sleep(2)
        pic_path = f'/Users/cichengzi/Desktop/code/UnmannedSupermarketSimulationSystem/resources/{start}.jpg'
        status_codes = download_image(commodity_info['thumb_url'], pic_path)
        print(f'epoch {start}...')
        if status_codes != 200:
            print('fail.')
            break
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
    return start


'''
url = 'https://img.pddpic.com/gaudit-image/2022-03-02/0ca49f34d9f188d9da231d48c60bafe9.jpeg'
path = ''
download_image(url, path)
'''

start = 1
for page in range(1, 11):
    download_info(page)
    commodity_info_list = json.load(open('cache/goods.txt'))['result']
    start = extract_commodities(commodity_info_list, start)