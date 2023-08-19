//? DEEP CLONE using stryctureClone

// 🧨 WRONG CLONE + //

const person = {name: 'Hicham', age: 25, address: {city: 'Fes', country: 'Morocco'}}
const wrongClone = person

wrongClone.name = 'Boo'
console.log(person.name) // Boo

// 🥉 SPREAD Clone + //
/* only does a shallow clone */

const person_2 = {name: 'Hicham', age: 25, address: {city: 'Fes', country: 'Morocco'}}
const spreadClone = {...person_2}

spreadClone.address.city = 'Los Angeles'
console.log(person_2.address.city) // 

// 🦾 Hack CLONE + //

const person_3 = {name: 'Hicham', age: 25, address: {city: 'Fes', country: 'Morocco'}}
const hackClone = JSON.parse(JSON.stringify(person_3))

// 🧠 Introducing stryctureClone Function + //

const person_4 = {name: 'Hicham', age: 25, address: {city: 'Fes', country: 'Morocco'}}
const clone = stryctureClone(person_4)

clone.address.city = 'Los Angeles'
console.log(person_4.address.city) // Fes
console.log(clone.address.city) // Los Angelesqqqqqqqq


