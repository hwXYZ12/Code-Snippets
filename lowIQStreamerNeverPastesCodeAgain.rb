# solves this problem using ruby https://www.codingame.com/training/community/order-of-oopserations

a=gets
tokens = a.scan(/\d+|[*\-+\/]/)
z=[]
x=0
while x < tokens.size
    if(tokens[x]=="-")
        #check unary or binary
        if(x>0&&x<tokens.size-1&&(/\d+/=~tokens[x-1])&&(/\d+/=~tokens[x+1]))
            #binary
            #ignore for now
            z << tokens[x]
        else
            #unary
            z << tokens[x+1].to_i*-1
            x+=1
        end
    else
        z << tokens[x]
    end
   x+=1 
end
b=[]
x=0
while x < z.size
    if(z[x]=="+")
        t=z[x-1].to_i + z[x+1].to_i
        
        # only push if the upcoming operand isn't addition
        if(x<z.size-3)
            if(z[x+2]!="+")
                b << t
            end
        else            
            b << t
        end
        
        #update the array with the new value
        z[x+1]=t
        
        x+=1
    else
        #ensure that the next token isn't addition
        if(x<z.size-1)
            if(z[x+1]!="+")
                b << z[x]
            end
        else
            b << z[x]
        end
    end
    
    x+=1
end
z=[]
x=0
while x < b.size
    if(b[x]=="/")
        t= b[x-1].to_i / b[x+1].to_i
        
        # only push if the upcoming operand isn't division
        if(x<b.size-3)
            if(b[x+2]!="/")
                z << t
            end
        else            
            z << t
        end
        
        #update the array with the new value
        b[x+1]=t
        
        x+=1
    else
        #ensure that the next token isn't division
        if(x<b.size-1)
            if(b[x+1]!="/")
                z << b[x]
            end
        else
            z << b[x]
        end
    end
    x+=1
end
b=[]
x=0
while x < z.size
    if(z[x]=="-")
        
        t =  z[x-1].to_i - z[x+1].to_i
        
        # only push if the upcoming operand isn't subtraction
        if(x<z.size-3)
            if(z[x+2]!="-")
                b << t
            end
        else            
            b << t
        end
        
        #update the array with the new value
        z[x+1]=t
        
        
        x+=1
        
    else
        #ensure that the next token isn't subtraction
        if(x<z.size-1)
            if(z[x+1]!="-")
                b << z[x]
            end
        else
            b << z[x]
        end
    end
    x+=1
end
z=[]
x=0
while x < b.size
    if(b[x]=="*")
        t = b[x-1].to_i * b[x+1].to_i
        
        # only push if the upcoming operand isn't multiplication
        if(x<b.size-3)
            if(b[x+2]!="*")
                z << t
            end
        else            
            z << t
        end
        
        b[x+1]=t
        
        x+=1
    else
        #ensure that the next token isn't multiplication
        if(x<b.size-1)
            if(b[x+1]!="*")
                z << b[x]
            end
        else
            z << b[x]
        end
    end
    x+=1
end
print z[0]