

def main(*args, **kwargs):
    input_list = map(int, raw_input().split())
    k = int(raw_input())
    d = {}
    for i in xrange(len(input_list)):
        d[input_list[i]] = i;
    count = 0
    for i in xrange(len(input_list)):
        if k - input_list[i] in d.keys() and d[ k - input_list[i]] != i :
            count = count + 1
    print count

if __name__ == '__main__':
    main()
