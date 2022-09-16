line = input()
alphabat = {}
for x in line.lower():
    if x not in alphabat.keys():
        alphabat[x] = 1
    else:
        alphabat[x] += 1

m_alphabat = [key for key, value in alphabat.items() if max(alphabat.values()) == value]

if len(m_alphabat) == 1:
    print(m_alphabat[0].upper())
else:
    print("?")

