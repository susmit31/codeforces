package main

import "fmt"

func min(a,b int) int{
	if a < b{
		return a
	} else{
		return b
	}
}

func max(a,b int) int{
	if a > b{
		return a
	} else{
		return b
	}
}

func main(){
	var N_INPUTS, turn int
	var left, right []int

	fmt.Scanf("%d\n", &N_INPUTS)
	var inputs [][3]int
	var n, a, b int
	
	for turn=0; turn<N_INPUTS; turn++{
		fmt.Scanf("%d %d %d\n", &n, &a, &b)
		inputs = append(inputs, [3]int{n, a, b})
	}
	
	for _, inp := range inputs{
		n, a, b = inp[0], inp[1], inp[2]
		left = []int{}
		right = []int{}
		in_arr := make(map[int]int)
		for num:=1; num <= n; num++{
			if num < min(a,b) && len(right) < n/2{
				right = append(right, num)
				in_arr[num] = 1
			} else if num > max(a,b) && len(left) < n/2{
				left = append(left, num)
				in_arr[num] = -1
			} else{
				in_arr[num] = 0
			}
		}
		for num:=1; num<=n; num++{
			if num >= a && num != b && in_arr[num] == 0{
				left = append(left, num)
				in_arr[num] = -1
				if len(left) == n/2{
					break
				}
			}
		}
		for num:=1; num<=n; num++{
			if num <=b && num != a && in_arr[num] == 0{
				right = append(right, num)
				in_arr[num] = 1
				if len(right) == n/2{
					break
				}
			}
		}
		if len(left) < n/2 || len(right) < n/2 {
			fmt.Printf("-1")
		} else{
			for _, num := range left{
				fmt.Printf("%d ", num)
			}
			for _, num := range right{
				fmt.Printf("%d ", num)
			}
		}
		fmt.Println()
	}
}