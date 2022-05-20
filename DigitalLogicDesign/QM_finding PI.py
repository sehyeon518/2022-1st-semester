def solution(minterm):
    variable = minterm[0]  # 0또는1의 개수 input 숫자 길이
    nOfMin = minterm[1]  # minterm 개수
    print("nOfMin       :", nOfMin)

    # mintem 순서를 dictionary로 >> 나중에 answer.sort(key=lambda k: my_priority[k])
    my_priority = make_dictionary(variable)

    # 입력받은 minTerms를 일차원 리스트에 나열
    mTerm = []
    for i in range(2, len(minterm)):
        mTerm.append(str(bin(minterm[i]))[2:].zfill(variable))
    print("mTerm        :", mTerm)

    # 1의 개수에 따른 2차원 리스트로
    minDimension = []
    for i in range(variable + 1):
        lis = []
        for x in mTerm:
            if i == x.count('1'):
                lis.append(x)
        minDimension.append(lis)
    print("minDimension :", minDimension)

    unchecked = sum(minDimension, [])
    print("unchecked  :" , unchecked)
    print("^^^^^^^^^^combine", "시작^^^^^^^^^^^")
    # variable 만큼 combine하며 한단계 combine할 때마다 minDimension을 갱신
    # combine 불가능한 minterm은 Answer에 추가
    var = variable
    for i in range(variable):
        mD = []

        for v in range(var):
            lis, unchecked = combine(minDimension[v], minDimension[v + 1], variable, unchecked)
            mD.append(lis)
        print("unchecked  :", unchecked)

        var -= 1
        print("mD           :", mD)
        print("^^^^^^^^combine", variable - v, "번 실행^^^^^^^^^")
        minDimension = mD
    Answer = sum(minDimension, [])
    print("unchecked  :", unchecked)
    Answer += unchecked

    Answer.sort(key=lambda k: my_priority[k])
    return Answer


def make_dictionary(v):
    dic = {}
    for i in range(3 ** v):
        x = i
        term = ''
        for j in range(v):
            if x % 3 == 1:
                term = '1' + term
            elif x % 3 == 2:
                term = '-' + term
            else:
                term = '0' + term
            x //= 3
        dic[term] = i
    return dic


def combine(lis1, lis2, v, uc):
    lis = []
    for i in lis1:
        for j in lis2:
            implct = ''
            count = 0
            for t in range(v):
                if i[t] == j[t]:
                    implct += i[t]
                else:
                    implct += '-'
                    count += 1
            if count == 1 or i == j:
                if implct not in lis:
                    lis.append(implct)
                if implct not in uc:
                    uc.append(implct)
                if i in uc:
                    uc.remove(i)
                if j in uc:
                    uc.remove(j)

    print("combine      :", lis)
    return lis, uc


print("Answer       :", solution([4, 8, 0, 4, 8, 10, 12, 11, 13, 15]))
