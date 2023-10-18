const { performance } = require('perf_hooks')

function linear_search(v, needle, length) {
  for(let i = 0; i < length; ++i) {
    if(v.at(i) == needle) {
      return true
    }
  }

  return false

}

let list = []

for(let i = 0; i < 10000; ++i) {
  list.push(i)
}

var startTime = performance.now()

let meow = linear_search(list, 9999, 9999)

var endTime = performance.now()

console.log(`found: ${meow}`)
console.log(`${endTime - startTime} milliseconds`)
