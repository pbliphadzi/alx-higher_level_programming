#!/usr/bin/node

const [,, input] = process.argv;
const x = Math.floor(Number(input));

if (isNaN(x) || x <= 0) {
  console.log('Please provide a valid positive number of occurrences');
} else {
  for (let i = 0; i < x; i++) {
    console.log('C is fun');
  }
}