const input = require("fs")
    .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
    .toString()
    .trim()
    .split("\n");
    // .map((el) => el.split(" ").map(Number));

let N = +input[0];
let budgets = input[1].split(" ").map(Number);
let total = +input[2];

const isPossible = (limit) => {
    let sum = 0;
    for(let i = 0; i < N; i++){
        if(budgets[i] <= limit) sum += budgets[i];
        else sum += limit;
    }
    return sum <= total;
}

let left = 0;
let right = Math.max(...budgets) + 1;
let ans = 0;
while(left < right){
    mid = left + right >> 1;
    if(isPossible(mid)){
        left = mid + 1;
        ans = mid;
    }else right = mid;
}
console.log(ans);