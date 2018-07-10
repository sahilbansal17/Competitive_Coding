

#the function sorts input arr by the currently significant digit
def counting_sort(input_arr, exp)
  count_arr = Array.new(10, 0)
  result = Array.new(input_arr.size)

  	m = 10 ** (exp+1)
  	n = 10 ** exp
	
      #count occurence of currently significant digit
  	input_arr.each do |item|
    		count_arr[(item % m) / n] += 1
end

  #modify count_arr to show actual index	
  for i in 1...10
   	count_arr[i] = count_arr[i-1] + count_arr[i]
  end

  #creat output array	
  i = input_arr.size - 1		
  until i < 0 do
     	item = input_arr[i]
     	count_arr[(item % m) / n] -= 1
     	result[count_arr[(item % m) / n]] = item
     	i -= 1
  end

  result
	
 end

def radix_sort(arr)
  #find the maximum number to know number of digits
      maximum = arr.max
	
  #find up to what exponenent the nums in array are	
      exp = 0
	
  	until maximum == 0 do
    	   exp += 1
    	   maximum = maximum / 10
  	end

  	for i in 0...exp do
    	    arr = counting_sort(arr, i)
  	end

  	arr
end

array = [172, 46, 65, 90, 802, 24, 3, 76]
array = radix_sort(array)

print array
puts
