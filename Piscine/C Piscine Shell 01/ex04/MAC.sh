ifconfig | grep ether | tr -d '\t' | awk '{print $2}'
