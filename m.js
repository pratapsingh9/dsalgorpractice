const calcAge = (age) =>{
    return 2024 - age;
}


const years = [1000,500,60,4,6,4];

for (const year of years) {
    console.log(calcAge(year));
    console.log(calcAge(...year))
}