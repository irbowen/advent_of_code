import md5

key = 'bgvyzdsv'
count = 0
while (True):
  m = md5.new(key + str(count)).hexdigest()
  if (m[0] == '0' and m[1] == '0' and m[2] == '0' and m[3] == '0' and m[4] == '0'):
    print m
    break
  count = count + 1
print m
print count
  
