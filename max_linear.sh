for n_nodes in 10000 30000
do
    for dim in 1 2 3 4
    do 
        ./randmst 0 $n_nodes 3 $dim
    done
done