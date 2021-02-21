for n_nodes in 28, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144
do
    for dim in 1 2 3 4
    do 
        ./randmst 0 $n_nodes 3 $dim
    done
done