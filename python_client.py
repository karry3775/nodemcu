import httplib2, json

#lets create an instance of the httplib2.HTTP() class
http = httplib2.Http()

if 0:
    url = "http://192.168.43.250/toggle"
    response, content = http.request(url,"GET")
    print "response is", response
    print "content is", content

url_json = "http://192.168.43.250/jblink"
header = {"Content-Type":"application/json; charset=UTF-8"}
data = {"times":"10","delay":"500"}
resp, content = http.request(url_json,"POST",headers=header, body=json.dumps(data))
print resp
