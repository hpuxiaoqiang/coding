# -*- conding: utf-8 -*-
import csv
import requests
import re
from lxml import etree
from bs4 import BeautifulSoup
headers = {
    'User-Agent': ' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36',
    'Cookie':' _iuqxldmzr_=32; _ntes_nnid=97c5053280e17217609a224c2f8ebb10,1537184640412; _ntes_nuid=97c5053280e17217609a224c2f8ebb10; WM_TID=AORZKWhjkIG1YdsDHEtGHrbl1m6uUI53; mail_psc_fingerprint=2beb4adbce0a304cbe7d9efd4aed9b9a; usertrack=CrH+ZluflKCW3uW/AxdcAg==; __f_=1538824787795; __remember_me=true; JSESSIONID-WYYY=kwI%5CADIjgia1BS1MxJB%5CihRkMEAdI%5CPv5XJtBxtIjhhTTd0MOzPJnO01dPaS12qIU4Bw3iHH71gcqreXRGzE%2FOueDHE%5CihP4ex7j4hCciklttg5P5f14wiOBMwfn1qQ2tfWTGnyFRyK7u2HtjQA%5CS7fSEtbBkFtzrNo%2BBW0%2Bl7YUUipo%3A1540347969060; MUSIC_U=da9fc0541a6b8ab19c5143757d6ed99bee3a017d6b3baa195f6ca68d39eb5ff62eaca429c4ca93a3d8953bf87400f5e3a70b41177f9edcea; __csrf=e3bb0e0096c1835123a9834b1a114a95; WM_NI=%2BuY3ApOrMnDNR%2BPrKZ6KANGGF5jvD458fJAruHWPmoz16MmQn1SgjFwIFzc9dctCmN7vWK7JalMnxqV0J8e138huWc70NMnFfyPliCNfErmxnZMNvGCtuaDJk%2BlPDqUHblE%3D; WM_NIKE=9ca17ae2e6ffcda170e2e6eed9b444ba9f83b3ee43a69a8ab3d44b978b9ebaf36b8befaad5dc69f3e88ab9b62af0fea7c3b92ae9ab97d4c47c8dae838fc74692f5a093ca52f6958fafc64d86eba697c740f7e8aaabc47ab79899b1f065baeffaaef05baeef9d88e94eb5978a9be233a8bdbca4f046f5aa99acb642a3b4838ffb7b96f086d9e83bf1e8a896d669f5f082aeed4ea6a7a08dec498eba8b93f074ae8683aff54d81acbb82c742a9f5a4b1c77b9798ae8dc837e2a3; playerid=78842840'
}
res = requests.get('https://music.163.com/#/playlist?id=690478423',headers=headers)
print(res.text)
