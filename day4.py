import md5

key = 'bgvyzdsv'
count = 0
five_zeros = ' '
six_zeros = ' '
five_flag = False
six_flag = False
while (True):
  m = md5.new(key + str(count)).hexdigest()
  if (m[0] == '0' and m[1] == '0' and m[2] == '0' and m[3] == '0' and m[4] == '0'):
    five_zeros = m
    five_flag = True
    print 'Four zeros: ' + str(count)
  if (m[0] == '0' and m[1] == '0' and m[2] == '0' and m[3] == '0' and m[4] == '0' and m[5] == '0'):
    six_zeroes = m
    six_flag = True
    print 'Six zeros: ' + str(count)
  if (five_flag and six_flag):
    break
  count = count + 1 
