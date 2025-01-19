import temper
import datetime
import json


myfamily = {
  "child1" : {
    "name" : "Emil",
    "year" : 2004
  },
  "child2" : {
    "name" : "Tobias",
    "year" : 2007
  },
  "child3" : {
    "name" : "Linus",
    "year" : 2011
  }
}


print(myfamily["child1"])
print(myfamily["child2"])

x =  '{ "name":"John", "age":30, "city":"New York"}'

paresedX = json.loads(x)

for v in paresedX:
    print(v)

myiter =  ('apple', 'banana', 'cherry')
myit = iter(myiter)

try:
    print("Working Properly as per my type")

except:
    print("An exception occurred")


print(datetime.datetime.now().year)
print(temper.checknames())