package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
	"sort"
)

func main(){
	var N_INPS int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d", &N_INPS)
	//fmt.Println(N_INPS)
	var a int
	var test_cases [][]int
	for i:=0; i<N_INPS; i++{
		scanner.Scan()
		scanner.Scan()
		var weights []int
		for _, part := range strings.Split(scanner.Text(), " "){
			a, _ = strconv.Atoi(part)
			weights = append(weights, a)
		}
		test_cases = append(test_cases, weights)
	}
	var total_time int
	var locations string
	for _, testcase := range test_cases{
		total_time, locations = plan_buildings(testcase)
		fmt.Println(total_time)
		fmt.Println(locations)
	}
}

func plan_buildings(weights []int) (int, string){
	wts_idx_sorted := make([]int, len(weights))
	wts_sorted := make([]int, len(weights))
	copy(wts_sorted, weights)
	for idx, _ := range weights{
		wts_idx_sorted[idx] = idx+1
	}
	sort.Slice(wts_idx_sorted, func (i, j int) bool {return weights[i] > weights[j]})
	sort.Slice(wts_sorted, func(i, j int) bool {return weights[i] > weights[j]})
	//######################################################
	// interesting discovery:
	// can reverse a slice using the function sort.Slice(any_slice, func(i,j int) bool {return i > j})
	//######################################################
	
	var right, left []int
	right = append(right, 0)
	for i, _ := range wts_sorted{
		if i%2==1 {
			left = append(left, wts_idx_sorted[i])
		} else {
			right = append(right, wts_idx_sorted[i])
		}
	}
	sort.Slice(left, func(i, j int) bool {return i > j})
	for _, el := range right{
		left = append(left, el)
	}

	var total_time int
	for _, building := range left{
		
	}
	return 1, join_slice(left, " ")
}

func join_slice(sl []int, sep string) string{
	output := ""
	for i, el := range sl {
		output += strconv.Itoa(el)
		if i != len(sl){
			output += sep
		}
	}
	return output
}