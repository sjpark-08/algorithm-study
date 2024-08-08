const input = require("fs")
    .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
    .toString()
    .trim()
    .split("\n");
    // .map((el) => el.split(" ").map(Number));

const [N, M] = input[0].split(" ").map(Number);
const map = input.slice(1).map((el) => el.split(" ").map(Number));

const dx = [0, 0, -1, 1];
const dy = [-1, 1, 0, 0];
let queue = [];
let visited = new Array(1001);

for(let i = 0; i <= 1000; i++){
    visited[i] = new Array(1001);
}

const bfs = ((x, y) => {
    for(let i = 0; i <= N; i++){
        for(let j = 0; j <= M; j++){
            visited[i][j] = -1;
        }
    }
    queue.push([x, y, 0]);
    while(queue.length){
        let [cx, cy, dis] = queue.shift();
        if(visited[cx][cy] != -1) continue;
        visited[cx][cy] = dis;

        for(let i = 0; i < 4; i++){
            let nx = cx + dx[i];
            let ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1) continue;
            if(visited[nx][ny] != -1 || map[nx][ny] == 0) continue;
            queue.push([nx, ny, dis + 1]);
        }
    }
});

for(let i = 0; i < N; i++){
    for(let j = 0; j < M; j++){
        if(map[i][j] == 2){
            bfs(i, j);
            break;
        }
    }
}

for(let i = 0; i < N; i++){
    line = '';
    for(let j = 0; j < M; j++){
        if(visited[i][j] == -1 && map[i][j] == 0) line += '0';
        else line += visited[i][j];
        line += ' ';
    }
    console.log(line);
}
