package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
	//"sort"
	"math"
)

func main(){
	var N_INPS int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d", &N_INPS)
	var inps [][]int64
	var a int64
	for i:=0; i < N_INPS; i++ {
		scanner.Scan()
		scanner.Scan()
		var inp []int64
		for _, part := range strings.Split(scanner.Text(), " "){
			a, _ = strconv.ParseInt(part, 10, 64)
			inp = append(inp, a)
		}
		inps = append(inps, inp)
	}
	for _, inp := range inps {
		fmt.Println(compute_max(inp))
	}
}

func compute_max(arr []int64) int64{
	count := 0
	for i, _ := range arr {
		for arr[i]%2 == 0 {
			arr[i] /= 2
			count ++
		}
	}
	//sort.Slice(arr, func (x, y int) bool {return arr[x] < arr[y]})
	//arr[len(arr)-1] *= int64(math.Pow(2, float64(count)))
	max_el := 0
	for i, _ := range arr {
		if arr[i] > arr[max_el]{
			max_el = i
		}
	}
	arr[max_el] *= int64(math.Pow(2, float64(count)))
	return sum_arr(arr)
}

func sum_arr(arr []int64) int64{
	sum := int64(0)
	for _, num := range arr {
		sum += num
	}
	return sum
}