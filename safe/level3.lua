
require "common"

local testcase = lunit.TestCase("Level 3 Testcases")

function testcase.test_taint()
    safety_check(function () taint(5) end)
    safety_check(function () untaint(5) end)
    safety_check(function () a = 5 end)
    lunit.assert_pass(function () local a = 5 end)
end

function testcase.test_exit()
    safety_check(function () os.exit(0) end)
end

function testcase.test_file_mod()
    safety_check(function () io.open("/tmp/blah.txt") end)
    safety_check(function () f:seek("cur", 0) end)
    safety_check(function () f:flush() end)
    safety_check(function () f:close() end)
    safety_check(function () io.tmpfile() end)
end


f = io.tmpfile() -- open this before we go to level 3
setsafelevel(3)
local ret = lunit.run()
-- os.exit(ret)  -- unfortunately, we can't do this now
