from selenium import webdriver
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.support.wait import WebDriverWait
import requests
import time
import os
import json
import random

if not os.path.exists('cache/goods.txt'):
    URL = 'https://apiv2.pinduoduo.com/api/gindex/tf/query_tf_goods_info?tf_id=TFRQ0v00000Y_13400&page=1&size=100'
    r = requests.get(URL)
    txt = r.text
    if len(txt) > 0:
        with open('cache/goods.txt', 'w') as f:
            f.write(txt)
txt = open('cache/goods.txt', 'r').read()
goods = json.loads(txt)['result']
with open('../data/commodities.txt', 'w') as f:
    for g in goods:
        name = g['goods_name']
        if 'group_price' in g:
            price = g['group_price']
        else:
            price = g['normal_price']
        number = random.randint(100, 2000)
        idx = g['goods_id']
        description = g['short_name']
        f.write(name + ',' + str(price) + ',' + str(number) + ',' + str(idx) + ',' + description + '\n')
