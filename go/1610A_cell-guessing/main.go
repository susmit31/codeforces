package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
)

func main(){
	var N_INPS, width, height int
	var inputs [][2]int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N_INPS, _ = strconv.Atoi(scanner.Text())
	for i:=0; i<N_INPS; i++{
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d %d", &width, &height)
		inputs = append(inputs, [2]int{width, height})
	}
	for _, dims := range inputs{
		fmt.Println(min_points(dims[0], dims[1]))
	}
}

func min_points(width, height int) int{
	if width <  height{
		return min_points(height, width)
	}
	if width == height && height == 1{
		return 0
	} else if height == 1{
		return 1
	} else {
		return 2
	}
}