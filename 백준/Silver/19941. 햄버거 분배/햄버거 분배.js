const input = require("fs")
    .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
    .toString()
    .trim()
    .split("\n");
    // .map((el) => el.split(" ").map(Number));

let vars = input[0].split(" ").map(Number);
let N = vars[0], K = vars[1];
let str = input[1];
let person = [];
let hamburger = [];

for(let i = 0; i < N; i++){
    if(str[i] == 'P') person.push(i);
    else hamburger.push(i);
}

let pIdx = 0, hIdx = 0, ans = 0;
while(pIdx < person.length && hIdx < hamburger.length){
    if(Math.abs(person[pIdx] - hamburger[hIdx]) <= K){
        pIdx++; hIdx++;
        ans++;
    }else{
        if(person[pIdx] < hamburger[hIdx]) pIdx++;
        else hIdx++;
    }
}
console.log(ans);