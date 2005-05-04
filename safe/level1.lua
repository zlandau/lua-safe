
require "common"

local testcase = lunit.TestCase("Level 1 Testcases")

function testcase.test_execute()
    safety_check(function () os.execute(taint("echo")) end)
end

function testcase.test_eval()
    safety_check(function () loadstring(taint("print(5)")) end)
end

function testcase.load()
    safety_check(function () load(taint("something.lua")) end)
end

function testcase.test_file()
    safety_check(function () io.open(taint("filename")) end)
    safety_check(function () io.open("filename", taint("w")) end)

    local TMPFILE = "/tmp/safety_test.txt"
    local f = io.open(TMPFILE, "w")
    safety_check(function () f:write(taint("data")) end)
    safety_check(function () f:seek("cur", taint(1234)) end)
    safety_check(function () os.rename(taint(TMPFILE), "/tmp/something.txt") end)
    safety_check(function () os.rename(TMPFILE, taint("/tmp/something.txt")) end)
    safety_check(function () os.remove(taint(TMPFILE)) end)
    f:close()
    os.remove(TMPFILE)

    safety_check(function () io.popen(taint("filename")) end)
    safety_check(function () io.popen("filename", taint("w")) end)
end

setsafelevel(1)
lunit.run()
