package main

import (
	"fmt"
	"bufio"
	"os"
)

func main(){
	var N_INPS int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d\n", &N_INPS)
	var inputs []string
	for i:=0; i< N_INPS; i++{
		scanner.Scan()
		inputs = append(inputs, scanner.Text())
	}
	for _, input := range inputs{
		fmt.Println(num_steps(input))
	}
}

func num_steps (numstr string) int{
	var digit int
	fmt.Sscanf(numstr[len(numstr)-1:],"%d", &digit)
	if digit%2 == 0 {
		return 0
	}
	for idx, _ := range numstr{
		fmt.Sscanf(numstr[idx:idx+1], "%d", &digit)
		if digit%2 == 0 {
			if idx == 0{
				return 1
			} else {
				return 2
			}
		}
	}
	return -1
}