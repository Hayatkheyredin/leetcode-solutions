/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    const result = [];
    let i = 0;
    const n = intervals.length;

    // Phase 1: Left (No Overlap)
    // Push intervals that end before newInterval starts
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push(intervals[i]);
        i++;
    }

    // Phase 2: Overlap (Merge)
    // Merge while intervals start before (or exactly when) newInterval ends
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
        newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
        i++;
    }
    // Push the fully merged interval
    result.push(newInterval);

    // Phase 3: Right (No Overlap)
    // Push remaining intervals
    while (i < n) {
        result.push(intervals[i]);
        i++;
    }

    return result;
};