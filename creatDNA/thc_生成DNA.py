import random

def creatonedna(lenth):
    dna=""
    dicACGT = {0:"A",1:"C",2:"G",3:"T"}
    for i in range(lenth):
        dna+=dicACGT[random.randint(0,3)]
    return dna

def craet_errordna(dna):
    dicACGT = {0:"A",1:"C",2:"G",3:"T"}
    error_location = random.randint(0,DNAlenth-1)
    error_ACGTlist = ["A","C","G","T"]
    error_ACGTlist.remove(dna[error_location])
    changed_base = random.choice(error_ACGTlist)
    error_DNA = ""
    error_DNA = dna[:error_location]+changed_base+dna[error_location+1:] if error_location<DNAlenth-1 else dna[:error_location]+changed_base
    return error_DNA
    
def reverseComplement(dna):
    complement = {'A': 'T', 'T': 'A', 'C': 'G', 'G': 'C'}
    return ''.join(complement.get(base, '') for base in reversed(dna))


# 参数设置（修改这里的参数是安全的，其他参数慎重）
DNAlenth = 50   # 设置单条DNA的长度,bp
endDNA = 100000    # 设置想要生成的总条数
error_rate = 0.2    # 设置出错的概率，取值 [0,1)

# DNA数组的生成
correct_list=[]
error_list = []
haveDNA=0   # 记录实际生成的总条数

groupDNA = 0    # 记录等价DNA组的数量
while(haveDNA<endDNA):
    DNA = creatonedna(DNAlenth)
    tlist = []
    m = random.randint(50,90)
    n = random.randint(0,90-m)
    revDNA = reverseComplement(DNA)
    for i in range(m):
        tlist.append(DNA)
    for j in range(n):
        tlist.append(revDNA)
    correct_list.append(tlist)
    random_error = random.random()
    if_error = False
    if(random_error<= error_rate):
        if_error = True
        AND = craet_errordna(DNA)
        error_list.append([groupDNA,AND,DNA])
    groupDNA+=1
    haveDNA += m+n+bool(if_error == True)

# 正确数组与错误数组合并展开成一维数组
one_list = []
for sublist in correct_list:
    one_list.extend(sublist)
for sub_error in error_list:
    one_list.append(sub_error[1])
# print(haveDNA,len(one_list),len(error_list))
print(f"DNA总条数：\t{haveDNA}")
print(f"DNA组：\t\t{groupDNA}")
print(f"错误DNA数量：\t{len(error_list)}")
random.shuffle(one_list)    # 随机打乱

# 写入文件
filelabel = random.randint(1,10000)
filename = "DNA_"+str(DNAlenth)+"bp"+"_"+str(endDNA)+'_'+str(filelabel)+".txt"
fnew1 = open(filename,"w")
fnew1.write("haveDNA="+str(haveDNA)+'\n'+"groupDNA="+str(groupDNA)+'\n'+"errorDNA="+str(len(error_list))+'\n')
num_fasta = 0
for sub_DNA in one_list:
    num_fasta+=1
    fnew1.write(">GagakillGroup"+str(num_fasta)+'\n')
    fnew1.write(sub_DNA+'\n')

error_filename = "errorDNA_"+str(DNAlenth)+"bp"+"_"+str(endDNA)+'_'+str(filelabel)+".txt"
fnew2 = open(error_filename,"w")

b = 0
for sub_error in error_list:
    fnew2.write(sub_error[1]+"->"+sub_error[2]+'\n')
    b+=1
fnew2.write("errorDNA="+str(b))




