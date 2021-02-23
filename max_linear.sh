# 10, 65536, 32768, 16384, 256, 512, 1024, 2048, 4096, 8192
for n_nodes in 1000
do
    for dim in 4
    do
        ./main 0 $n_nodes 5 $dim
    done
done