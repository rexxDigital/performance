const { performance } = require('perf_hooks')

function binary_search(v, beginning, end, needle) {
  const start = v.at(beginning);
  const middle = beginning + ((end - beginning) / 2);

  if(needle == middle) {
    return middle;
  }

  if(needle > middle) {
    return binary_search(v, middle + 1, end, needle)
  } else {
    return binary_search(v, start, middle, needle)
  }
}

let list = []

for(let i = 0; i < 10000; ++i) {
  list.push(i)
}

var startTime = performance.now()

let meow = binary_search(list, 0, 10000, 7788)

var endTime = performance.now()

console.log(`found: ${meow}`)
console.log(`${endTime - startTime} milliseconds`)
