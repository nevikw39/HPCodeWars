#python 3.3

import sys
import string
import pdb

section = 'none'
mars_dict={}

while True:

  line = sys.stdin.readline()

  line=line.strip('\n')
  #
  # section parsing
  #
  if line == '[TEXTSPEAK]':
    section='TEXTSPEAK'
    continue
  
  if section == 'TEXTSPEAK' and line == '[\TEXTSPEAK]':
    section='none'
    continue
    
  if section=='none' and line == '[LOGIN_TITLE]':
    section = 'LOGIN_TITLE'
    continue
  
  if section == 'LOGIN_TITLE' and line=='[\LOGIN_TITLE]':
    section='none'
    break
    
  #
  # content parsing
  #
  if section == 'none':
    continue
    
  if section == 'TEXTSPEAK':
    a=line.split(': ')
    mars_dict[a[0]]=a[1]
  if section == 'LOGIN_TITLE':
    #for key in mars_dict.keys():
      #line.replace (key, mars_dict[key])
    #line.format(**mars_dict)
    
    
    line_segs=line.split()
    newline=''
    for seg in line_segs:
      
      isMatched = False
      for key in mars_dict.keys():
        if key == seg:
          seg=mars_dict[key]
          isMatched = True
          break
      
      # strip the symbol if it has in tail.
      if not isMatched:
        i = 1
        hasTailSymbol = False
        while seg[-i] not in string.ascii_letters and seg[-i] not in string.digits:
          hasTailSymbol = True
          i+=1
          if i > len(seg):
            break
        i-=1
        if hasTailSymbol:
          for key in mars_dict.keys():
            if key == seg[0:-i]:
              #seg = mars_dict[key] + seg[-i]
              seg = seg.replace(key, mars_dict[key])
              isMatched = True
      newline=newline + (' ' if newline != '' else '')+ seg

    print(newline)

