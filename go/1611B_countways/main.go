package main
import "fmt"

func countways(a, b int) int{
	if a > b{
		return countways(b, a)
	} else if a!=0 && b / a >= 3{
		return a
	} else if a==0 {
		return 0
	} else{
		d := b - a
		count := int(d / 2)
		b -= 3*count
		a -= count
		count += int((a+b)/4)
		return count
	}
}

func main(){
	var N_INPS, a, b ,i int
	fmt.Scanf("%d\n",&N_INPS)
	var inps [][2]int
	for i=0; i<N_INPS;i++{
		fmt.Scanf("%d %d\n", &a, &b)
		inps = append(inps,[2]int{a,b})
	}
	for _, inp := range inps{
		fmt.Println(countways(inp[0], inp[1]))
	}
}