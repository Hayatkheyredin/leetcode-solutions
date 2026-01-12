var latestDayToCross = function(row, col, cells) {
    const directions = [[1,0],[-1,0],[0,1],[0,-1]];
    
    const canCross = (day) => {
        const grid = Array(row).fill(0).map(() => Array(col).fill(0));
        
        for (let i = 0; i < day; i++) {
            const r = cells[i][0] - 1;
            const c = cells[i][1] - 1;
            grid[r][c] = 1;
        }
        
        const queue = [];
        const visited = Array(row).fill(0).map(() => Array(col).fill(false));
        
        for (let c = 0; c < col; c++) {
            if (grid[0][c] === 0) {
                queue.push([0, c]);
                visited[0][c] = true;
            }
        }
        
        while (queue.length > 0) {
            const [r, c] = queue.shift();
            
            if (r === row - 1) return true;
            
            for (const [dr, dc] of directions) {
                const nr = r + dr;
                const nc = c + dc;
                
                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    !visited[nr][nc] && grid[nr][nc] === 0) {
                    visited[nr][nc] = true;
                    queue.push([nr, nc]);
                }
            }
        }
        
        return false;
    };
    
    let left = 1, right = cells.length, answer = 0;
    
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        
        if (canCross(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return answer;
};