package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
	"sort"
	"math"
)

func main(){
	var N_INPS int64
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d", &N_INPS)
	var a,i int64
	var test_cases [][]int64
	for i=0; i<N_INPS; i++{
		scanner.Scan()
		scanner.Scan()
		var weights []int64
		for _, part := range strings.Split(scanner.Text(), " "){
			a, _ = strconv.ParseInt(part, 10, 64)
			weights = append(weights, a)
		}
		test_cases = append(test_cases, weights)
	}
	var total_time int64
	var locations string
	for _, testcase := range test_cases{
		total_time, locations = plan_buildings(testcase)
		fmt.Println(total_time)
		fmt.Println(locations)
	}
}

func plan_buildings(weights []int64) (int64, string){
	buildings_sorted := make([]int64, len(weights))
	for i,_ := range weights{
		buildings_sorted[i] = int64(i+1)
	}
	sort.Slice(buildings_sorted, func(i, j int) bool {return weights[i] > weights[j]})
	var left, right []int64
	right = append(right, 0)
	for i, building := range buildings_sorted{
		if i%2==0 {
			right = append(right, building)
		} else {
			left = append(left, building)
		}
	}
	sort.Slice(left, func(i, j int) bool {return i > j}) // reversing the left half
	city_map := left
	coords := make([]int64, len(weights)+1)
	for _, building := range right {
		city_map = append(city_map, building)
	}
	for i, building := range city_map {
		coords[building] = int64(i)
	}
	
	var travel_time int64 = 0
	var dist int64
	for i:=1; i < len(coords); i++ {
		dist = int64(math.Abs(float64(coords[i]) - float64(coords[0])))
		travel_time += int64(2)*dist*int64(weights[i-1])
	}
	return travel_time, join_slice(coords, " ")
}

func join_slice(sl []int64, sep string) string{
	output := ""
	for i, el := range sl {
		output += strconv.FormatInt(el, 10)
		if i != len(sl){
			output += sep
		}
	}
	return output
}