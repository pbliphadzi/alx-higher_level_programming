#!/usr/bin/node

const size = Math.floor(Number(process.argv[2]));

if (isNaN(size) || size <= 0) {
  console.log('Please provide a valid positive size');
} else {
  const row = 'X'.repeat(size); // Creating the row string directly
  for (let r = 0; r < size; r++) {
    console.log(row);
  }
}