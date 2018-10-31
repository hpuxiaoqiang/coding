# -*- coding:utf-8 -*-
import json
jsonString = '{"user_name":[{"name":"pater"},{"name":"xiaoming"}],"user_woman":[{"name":"Ali"},{"name":"xiaozhang"}]}'
json_data = json.loads(jsonString)
print(json_data.get("user_name"))
print(json_data.get("user_woman"))
print(json_data.get("user_name")[0].get("name"))