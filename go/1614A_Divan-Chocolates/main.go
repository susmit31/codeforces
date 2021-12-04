package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
	"sort"
)

func main(){
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N_INPS,_ := strconv.Atoi(scanner.Text())
	var choc_nums, lower_lims, upper_lims, budgets []int
	var prices [][]int
	var n, l, r, k int
	for i:=0; i<N_INPS; i++{
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d %d %d %d", &n,&l,&r,&k)
		choc_nums = append(choc_nums, n)
		lower_lims = append(lower_lims, l)
		upper_lims = append(upper_lims, r)
		budgets = append(budgets, k)

		price := make([]int, n)
		scanner.Scan()
		for _, s := range strings.Split(scanner.Text()," "){
			newprice, _ := strconv.Atoi(s)
			price = append(price, newprice)
		}
		prices = append(prices, price)
	}
	for i:=0; i<N_INPS;i++{
		fmt.Println(count_purchases(choc_nums[i],lower_lims[i],upper_lims[i],budgets[i],prices[i]))
	}
}

func count_purchases(n, l, r, k int, price []int) int{
	sort.Ints(price)
	var count int = 0
	for _, p := range price{
		if l <= p && p <= r && k >= p{
			count++
			k -= p
		}
	}
	return count
}