// rgba(1, 88, 80)
// rgba(36, 40, 157)
// rgba(255, 255, 255)

let arr = [
    [1, 88, 80],
    [30, 40, 157]
];

for (let i = 0; i < arr.length; i++) {
    arr[i].forEach(item => {
        console.log([item/255]);
    })
}
    
