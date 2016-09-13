--
-- Lua 5.2 & Luna Five: Account Example
-- Date: 16 May 2013
-- Website: http://blog.p86.dk
--

-- Override Lua Print()
local print = function (x)
  print("Lua: "..x)
end

local a1 = Account(100)
print("Created Account 1 with $"..a1:getBalance().." balance")

cash = 50
a1.deposit(cash)
print("Account 1: Depositing $"..cash)

print("Account 1: New Balance is $"..a1:getBalance())

cash = 25
a1.withdraw(cash)
print("Account 1: Withdrawing $"..cash)

print("Account 1: New Balance is $"..a1:getBalance())


-- Open a 2nd Account
local a2 = Account(1000)
print("Created Account 2 with $"..a2:getBalance().." balance")

cash = 500
a2.deposit(cash)
print("Account 2: Depositing $"..cash)

print("Account 2: New Balance is $"..a2:getBalance())

cash = 250
a2.withdraw(cash)
print("Account 2: Withdrawing $"..cash)

print("Account 2: New Balance is $"..a2:getBalance())


-- Check the 1st Account Again
print("Account 1: New Balance is $"..a1:getBalance())
cash = 25
a1.withdraw(cash)
print("Account 1: Withdrawing $"..cash)

print("Account 1: New Balance is $"..a1:getBalance())

local a3 = Account(100)
a3.X = 202;
print("X equals " .. a3.X)

print("End of Script")
