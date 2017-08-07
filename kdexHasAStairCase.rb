# solution to the following problem
# found on https://www.codingame.com/
# and the problem is contributed by kdex___
# (roughly paraphrased)
#
# An integer staircase is produced by concatenating
# integers 1,2,3,...,n-1,n,n-1,n-2,...3,2,1
# without commas
# ex:
# 12345678910111213121110987654321
# is an integer staircase
# Write a program that takes a string of integers
# and determines whether or not the string is an integer staircase

@c = gets.to_i
@n = gets.chomp
up=true
if @n[0]!="1"
    p false
    exit
elsif @c == 1
    p true
    exit
end

lastValue=1
x=1
while(x < @c)
    
    if up
        expectedValue = lastValue + 1
    else
        expectedValue = lastValue - 1
    end
    
    actualValue = -1
    z=expectedValue.to_s.size
    if x+z-1 < @n.size && z > 1
        actualValue = @n[x..x+z-1].split("").inject(0){|a,b|10*a.to_i+b.to_i}
    else
        actualValue = @n[x].to_i
    end
    #puts expectedValue
    #puts actualValue
    #puts z
    
    if up
        if actualValue != expectedValue
            up=false
            expectedValue = lastValue - 1
            z=expectedValue.to_s.size
            if x+z-1 < @n.size && z > 1
                actualValue = @n[x..x+z-1].split("").inject(0){|a,b|10*a.to_i+b.to_i}             
            else
                actualValue = @n[x].to_i
            end 
            if actualValue != expectedValue
                p false
                exit
            end
        end
    else            
        if actualValue != expectedValue
            p false
            exit
        end
    end
    lastValue = actualValue
    x+=z
end
p true