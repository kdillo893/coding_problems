

from hashlib import md5


text = "something silly and very long that can be pushed\
    through an md5 hash algorithm."

myMD5 = md5.hexdigest(text)

print(myMD5)
