require "lunit"

testcase = lunit.TestCase("Safety Level Testcase")

-- level 0 tests

function testcase.test_taint()
    local var = 5
    lunit.assert_false(istainted(var))
    var = taint(var)
    lunit.assert_true(istainted(var))
end

-- level 1 tests
-- level 2 tests
-- level 3 tests

function testcase.test_execute()
    lunit.assert_error(function () os.execute(taint("echo")) end)
end


-- level 4 tests




lunit.run()
