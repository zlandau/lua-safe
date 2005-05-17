
function echo_cmd()
    io.write("\tEnter a string to call echo on: ")
    local input = io.read()
    local command = "echo " .. input
    return command
end


print("Insecure version: ")
local command = echo_cmd()
print("\tCalling `" .. command .."`")
os.execute(command)

print("\n")

setsafelevel(3)
print("Safety violation version: ")
local ret, err = pcall(function ()
    local command = echo_cmd()
    print("\tCalling `" .. command .."`")
    os.execute(command)
end)

print(err)

print("Handling the data: ")
local command = echo_cmd()
command = string.format("%q", command)
print("\tCalling `" .. command .."`")
os.execute(command)
