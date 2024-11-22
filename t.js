let array = ["sadf", "ad", "a", "asfd"];

function mergeSort(array) {
    const mid = Math.floor(array.length/2);

    const left = mergeSort(array.slice(0,mid));
    const right = mergeSort(array.slice(mid));

    return merge(left,right)
}


const merge = (arr1,arr2)