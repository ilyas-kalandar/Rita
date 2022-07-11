# Надеюсь пух все еще живой...
# Скоммуниздил отсюда https://github.com/fakefloordiv/rush/blob/rush3-dev/linesofcode.py

fs,ls=[],0;exec('p=print\ndef g(b):\n\tglobal ls\n\twith open(b)as f:a=len(f.readlines());ls+=a;return a')
for t,_,c in __import__('os').walk('.'):fs+=[t+'/'+fl for fl in c if ((fl.endswith("cpp") or fl.endswith(".h") or fl.endswith('.hpp')) and not fl.startswith("CMake"))]
for a,b in sorted([(f,g(f))for f in fs if'init'not in f],key=lambda i:i[1])[::-1]:p(a[2:],' '*(len(max(fs,key=len))-len(a)+11),b,' '*(4-len(str(b)))+'lines of code')
p('-'*57+'\nTotal lines:',ls)
