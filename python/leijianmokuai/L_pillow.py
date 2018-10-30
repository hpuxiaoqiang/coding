# -*- coding:utf-8 -*-
import random
from PIL import Image,ImageFilter,ImageDraw,ImageFont
im = Image.open('test.png')
#缩小
# w,h = im.size
# print('original image size;%s*%s'%(w,h))
# im.thumbnail((w/2,h/2))
# print('Resize image to : %s * %s'%(w/2,h/2))
# im.save('thumbnail.jpg','jpeg')

#模糊化
# im2  = im.filter(ImageFilter.BLUR)
# im2.save('blur.jpg','jpeg')

#生成验证码
def randchar():
    return chr(random.randint(65,90))
def randcolr():
    return (random.randint(64,255),random.randint(64,255),random.randint(64,255))
def randcolr2():
    return (random.randint(32,127),random.randint(32,127),random.randint(32,127))
width = 60*4
height = 60
image = Image.new('RGB',(width,height),(255,255,255))
font = ImageFont.truetype('/usr/share/fonts/truetype/tlwg/TlwgTypist-Oblique.ttf',36)
draw = ImageDraw.Draw(image)
for x in range(width):
    for y in range(height):
        draw.point((x,y),fill = randcolr())
for i in range(4):
    draw.text((60*i + 10,10),randchar(),font = font,fill = randcolr2())
# image = image.filter(ImageFilter.BLUR)
image.save('code.jpg','jpeg')