
require "common"

local testcase = lunit.TestCase("Level 2 Testcases")

function testcase.test_taint()
    local var = 5
    lunit.assert_true(istainted(var))
    global = 5
    lunit.assert_true(istainted(global))
    safety_check(function () untaint(global) end)
end

setsafelevel(2)
local ret = lunit.run()
os.exit(ret)
