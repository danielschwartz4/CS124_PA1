for n_nodes in 10, 65536, 32768, 16384, 256, 512, 1024, 2048, 4096, 8192
do
    for dim in 1 2 3 4
    do
        ./randmst 0 $n_nodes 5 $dim
    done
done